#! /bin/bash

# Simple test for the count_vowels program.

run () {
  echo "$*"
  if $*
  then echo 'success'
  else echo 'error'
  fi
}

run ./range <<EOF 1 2 3 4 5 6 7 8 9 21
EOF
echo '-----------------------------------'

run ./range << EOF 8 9 10
EOF
echo '-----------------------------------'

run ./range <<EOF 2 9 10 8
EOF
echo '-----------------------------------'

run ./range <<EOF 18 9
EOF
echo '-----------------------------------'

run ./range <<EOF 2
EOF

exit 0
