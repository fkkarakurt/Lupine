#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# File              : LPCore-gdb.py
# Author            : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>
# Date              : 28.05.2022
# Last Modified Date: 28.05.2022
# Last Modified By  : Fatih Küçükkarakurt <fatihkucukkarakurt@gmail.com>

import gdb
import re

class LPStringPrinter:
    def __init__(self, val):
        self.val = val

    def to_string(self):
        bufType = self.val['m_pStringBuffer']['m_nType']
        if bufType == 0:
            ty = gdb.lookup_type('LupineCore::StringBufferASCII').pointer();
            return self.val['m_pStringBuffer'].cast(ty)['m_pszString']
        elif bufType == 1:
            ty = gdb.lookup_type('LupineCore::StringBufferUnicode').pointer();
            return self.val['m_pStringBuffer'].cast(ty)['m_pszString'].string('UTF-32')
        return None

    def display_hint(self):
        return 'string'

    def register_lp_printers(obj):
        if obj == None:
            obj = gdb

        obj.pretty_printers.append(lookup_function)

    def lookup_function(val):
        "Look-up and return a pretty printer that can print val."

        type = val.type;

        if type.code == gdb.TYPE_CODE_REF:
            type = type.target()

        type = type.unqualified ().strip_typedefs()
        typename = type.tag
        
        if typename == None:
            return None

        for function in pretty_printers_dict:
            if function.search(typename):
                return pretty_printers_dict[function] (val)

        return None

    
    def build_dictionary():
        pretty_printers_dict[re.compile('^LupineCore::String$')] = lambda val: LPStringPrinter(val)

    pretty_printers_dict = {}

    build_dictionary()

    register_lp_printers(gdb.current_objfile())
