#!/usr/bin/env python
# -*- coding:utf-8 -*-
# The build entrance of UniProton.

#
# Copyright (c) 2021-2023 Huawei Device Co., Ltd.
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

import os
import re
import sys
import time
import logging
import globle


logging.basicConfig(level=logging.NOTSET) 

class BuilderNolog():

    def __init__(self,log_file):
        self.log_file = log_file
        self.loglevel = 'INFO'

    def run(self, cmd, cwd=os.getcwd(), env=None):
        exit_code = os.system('cd %s && %s' % (cwd, cmd))
        if exit_code != 0:
            with open(self.log_file) as file_handle:
                for line in file_handle.readlines():
                    logging.info(line)
            logging.info("\n--[INFO] more message in logfile [%s] env: [%s]" ,self.log_file, env)
        return exit_code

    def log_format(self):
        try:
            sys.path.append(("%s%s") % (globle.home_path, "/../cmake"))
            import logcode_format
            formatter = (logcode_format.init_format(os.getcwd().split('/')[-1]))
        except ImportError:
            formatter = '%(asctime)s -- %(levelname)s [UniProton] -- : %(message)s'

        logger_root = logging.getLogger()
        for handler in logger_root.handlers:
            logger_root.removeHandler(handler)

        with open(self.log_file, 'r') as rd:
            lines = rd.readlines()
        os.remove(self.log_file)

        logformat = logging.Formatter(formatter)
        fh = logging.FileHandler(self.log_file, mode='a', encoding=sys.getdefaultencoding())
        fh.setLevel(self.loglevel)
        fh.setFormatter(logformat)

        logger = logging.getLogger('UniProton')
        logger.setLevel(self.loglevel)
        for handler in logger.handlers:
            logger.removeHandler(handler)
        logger.addHandler(fh)

        for line in lines:
            logger.info(line.strip())
        return


def log_msg(level,msg):
    logging.info('[%s] %s %s %s', level.upper(),'#'*20,msg,'#'*20)
