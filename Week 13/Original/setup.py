#!/usr/bin/env python

from distutils.core      import setup
from distutils.extension import Extension


long_description = ''''''

setup(name             = 'srp',
      version          = '1.0.16',
      description      = 'Secure Remote Password',
      author           = 'Tom Cocagne',
      author_email     = 'tom.cocagne@gmail.com',
      url              = 'https://github.com/cocagne/pysrp',
      download_url     = 'http://pypi.python.org/pypi/srp',
      long_description = long_description,
      provides         = ['srp'],
      install_requires = ['six'],
      packages         = ['srp'],
      package_data     = {'srp' : ['doc/*.rst', 'doc/*.py']},
      license          = "MIT",
      platforms        = "OS Independent",
      classifiers      = [
        'Development Status :: 5 - Production/Stable',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: BSD License',
        'Operating System :: OS Independent',
        'Programming Language :: Python :: 2.7',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python',
        'Topic :: Security',
        ],)
