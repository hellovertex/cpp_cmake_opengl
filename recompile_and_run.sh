#!/bin/bash
# shellcheck disable=SC2046
SCRIPT_DIRECTORY="$(dirname $(realpath "$0"))"
source "$SCRIPT_DIRECTORY"/_configure.sh
source "$SCRIPT_DIRECTORY"/_build.sh
source "$SCRIPT_DIRECTORY"/_run_tests.sh
source "$SCRIPT_DIRECTORY"/_run.sh
