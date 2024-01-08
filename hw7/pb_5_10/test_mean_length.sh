#! /bin/bash


run () {
  echo "$*"
  if $*
  then echo 'success'
  else echo 'error'
  fi
}

run ./mean_length "toast" "bob" "chicken"
echo '-----------------------------------'

run ./mean_length "soop" "run" "copper"
echo '-----------------------------------'

run ./mean_length "green" "blue" "sid"
echo '-----------------------------------'

run ./mean_length 8
echo '-----------------------------------'

run ./mean_length <<EOF
EOF

exit 0
