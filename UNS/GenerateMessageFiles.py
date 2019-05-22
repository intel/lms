#!/usr/bin/env python3
# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2018 Intel Corporation

import argparse
import codecs

class MessageProcessor(object):

# ComputeErrorCode - a subroutine for computing error codes in Windows style (See Winerror.h).
# Code is a 32 bit value laid out as follows:
# 2 bits for severity (00 - success, 01 - informational, 10 - warning, 11 - error)
# 1 bit for customer code flag - always 0 (Although MS says that when its clear it states on MS code...)
# 1 bit for reserved bit
# 12 bits for facility
# 16 bits (2 bytes)for code
    def __compute_code(self, typedef, severity, facility, code):
        return "(({0}){1:#x}L)".format(typedef, severity << 30 | facility << 27 | code)

    def __severity2int(self, severity_str):
        if severity_str.upper() == "SUCCESS":
            return 0
        if severity_str.upper() == "INFORMATIONAL":
            return 1
        if severity_str.upper() == "WARNING":
            return 2
        if severity_str.upper() == "ERROR":
            return 3
        raise IndexError

    def __facility2int(self, facility_str):
        if facility_str.upper() == "APPLICATION":
            return 0
        raise IndexError

    def prepare_element(self):
        return "#define " + self.SymbolicName + " " + \
            self.__compute_code(self.MessageIdTypedef, \
                 self.__severity2int(self.Severity), \
                 self.__facility2int(self.Facility), int(self.MessageId)) + '\n'

    def prepare_element_comment(self):
        return """//
// MessageId: {0}
//
// MessageText:
//
// {1}
//
""".format(self.MessageId, self.Text)

    def prepare_msg(self):
        return '\t{{ {0}, "{1}" }},\n'.format(self.SymbolicName, self.Text)

    def process_line(self, line):
        if line[0] == ';': #comment
            self.header_str += line[1:]
        parts = line.strip('\n').split('=')
        if parts[0] == "MessageIdTypedef":
            self.MessageIdTypedef = parts[1]
            return
        if parts[0] == "MessageId":
            self.MessageId = parts[1]
            self.Text = ''
            self.in_message = True
            return
        if parts[0] == ".":
            self.in_message = False
            self.header_str += self.prepare_element_comment()
            self.header_str += self.prepare_element()
            self.header_str += '\n'
            self.message_str += self.prepare_msg()
            return
        if parts[0] == "Facility":
            self.Facility = parts[1]
            return
        if parts[0] == "Severity":
            self.Severity = parts[1]
            return
        if parts[0] == "SymbolicName":
            self.SymbolicName = parts[1]
            return
        if parts[0] == "Language":
            self.Language = parts[1]
            return
        if self.in_message:
            self.Text += parts[0]

    def __init__(self, path):

        self.header_str = ''
        self.message_str = """#ifndef UNS_MESSAGES_TEXT
#define UNS_MESSAGES_TEXT
#include <stdint.h>
#include <string>
#include <map>

static const std::map<uint32_t, std::string> UNSMessages = {
"""
        self.MessageIdTypedef = ''
        self.in_message = False

        with codecs.open(path, 'r', 'UTF-8') as the_file:
            for line in the_file:
                self.process_line(line)

        self.message_str += """
};
#endif // UNS_MESSAGES_TEXT
"""

if __name__ == '__main__':

    parser = argparse.ArgumentParser(description='Parse UNS message file.')
    parser.add_argument('source_file', type=str, nargs=1,
                        help='full name with path of UNSMessageFile.mc')
    parser.add_argument('header_file', type=str, nargs=1,
                        help='full name with path of UNSMessageFile.h')
    parser.add_argument('message_file', type=str, nargs=1,
                        help='full name with path of UNSMessageMap.h')

    args = parser.parse_args()
    processor = MessageProcessor(args.source_file[0])
    with open(args.header_file[0], 'w') as the_header:
        the_header.write(processor.header_str)
    with open(args.message_file[0], 'w') as the_message:
        the_message.write(processor.message_str)
