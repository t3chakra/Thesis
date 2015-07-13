#!/bin/bash
IFS=$'\n'
grade=0

check_case_1_4()
{
  cat stdout | sed -e '/^$/d' > stdout.2
  mv stdout.2 stdout
  head stdout -n 1 | grep "^Error" >/dev/null 2>1
  if [ $? -ne 0 ];then
    echo "@@@@@Should stdout begin with Error, but stdout 1st line is"
    head stdout -n 1
    return 0
  fi
  (( grade = grade + 5 ))
  echo "This Case passed: 5 point."
}

check_case_5()
{
  cat stdout | sed -e '/^$/d' > stdout.2
  mv stdout.2 stdout
  #if [ `ls -lah stderr | awk '{ print $5}'` -ne 0 ];then
  #  echo "@@@@@Should not have stderr, but stderr 1st line is "
  #  head stderr -n 1
  #  return 0
  #fi
  if [ `cat stdout | wc -l` -ne 1 ];then
    echo "@@@@@Should has 1 lines in stdout, but stdout has"
    cat stdout | wc -l
    return 0
  fi

  head stdout -n 1 | grep "^0-1-2-3-4$" >/dev/null 2>1
  if [ $? -ne 0 ];then
    echo "@@@@@Should stdout be 0-1-2-3-4 , but stdout 1st line is"
    head stdout -n 1
    return 0
  fi

  (( grade = grade + 15 ))
  echo "Case 5 passed: 15 point."
}

check_case_6()
{
  cat stdout | sed -e '/^$/d' > stdout.2
  mv stdout.2 stdout
  #if [ `ls -lah stderr | awk '{ print $5}'` -ne 0 ];then
  #  echo "@@@@@Should not have stderr, but stderr 1st line is "
  #  head stderr -n 1
  #  return 0
  #fi
  if [ `cat stdout | wc -l` -ne 1 ];then
    echo "@@@@@Should has 1 lines in stdout, but stdout has"
    cat stdout | wc -l
    return 0
  fi

  head stdout -n 1 | grep "^0-2-1-4$" >/dev/null 2>1
  if [ $? -ne 0 ];then
    echo "@@@@@Should stdout be 0-2-1-4 , but stdout 1st line is"
    head stdout -n 1
    return 0
  fi

  (( grade = grade + 20 ))
  echo "Case 6 passed: 20 point."
}

check_case_7()
{
  cat stdout | sed -e '/^$/d' > stdout.2
  mv stdout.2 stdout
  #if [ `ls -lah stderr | awk '{ print $5}'` -ne 0 ];then
  #  echo "@@@@@Should not have stderr, but stderr 1st line is "
  #  head stderr -n 1
  #  return 0
  #fi
  if [ `cat stdout | wc -l` -ne 1 ];then
    echo "@@@@@Should has 1 lines in stdout, but stdout has"
    cat stdout | wc -l
    return 0
  fi

  head stdout -n 1 | grep "^0-3-7-10-12$" >/dev/null 2>1
  if [ $? -ne 0 ];then
    echo "@@@@@Should stdout be 0-3-7-10-12 , but stdout 1st line is"
    head stdout -n 1
    return 0
  fi

  (( grade = grade + 20 ))
  echo "Case 7 passed: 20 point."
}

#for f in `ls test/*.gz`
for f in `ls sub/*.gz`
do
  grade=0
  echo ""
  echo ""
  echo $f

  ROOT=`pwd`
  rm -rf work
  mkdir -p work
  cp "$f" work/a2-ece650.tar.gz
  cd work
  tar xvzf a2-ece650.tar.gz
  cd a2-ece650
  rm a2-ece650
  make clean
  rm a2-ece650
  make all
  ls
  cd $ROOT

  echo "###########################################"
  echo "Case: 0"
  sleep 1
  (( grade = grade + 20 ))
  echo "Case 0 passed by default: 20 point."
  echo "Point: " $grade

  echo "###########################################"
  echo "Case: 1"
  tail -n +4 test01.txt | work/a2-ece650/a2-ece650 > stdout 2>&1 &
  sleep 1
  kill $! > /dev/null 2>1
  if [ $? -eq 0 ]; then
    echo "@@@@@Program can not stop at EOF, or runs more than 1 second."
  else
    check_case_1_4
  fi
  echo "Point: " $grade

  echo "###########################################"
  echo "Case: 2"
  tail -n +4 test02.txt | work/a2-ece650/a2-ece650 > stdout 2>&1 &
  sleep 1
  kill $! > /dev/null 2>1
  if [ $? -eq 0 ]; then
    echo "@@@@@Program can not stop at EOF, or runs more than 1 second."
  else
    check_case_1_4
  fi
  echo "Point: " $grade

  echo "###########################################"
  echo "Case: 3"
  tail -n +4 test03.txt | work/a2-ece650/a2-ece650 > stdout 2>&1 &
  sleep 1
  kill $! > /dev/null 2>1
  if [ $? -eq 0 ]; then
    echo "@@@@@Program can not stop at EOF, or runs more than 1 second."
  else
    check_case_1_4
  fi
  echo "Point: " $grade

  echo "###########################################"
  echo "Case: 4"
  tail -n +4 test04.txt | work/a2-ece650/a2-ece650 > stdout 2>&1 &
  sleep 1
  kill $! > /dev/null 2>1
  if [ $? -eq 0 ]; then
    echo "@@@@@Program can not stop at EOF, or runs more than 1 second."
  else
    check_case_1_4
  fi
  echo "Point: " $grade

  echo "###########################################"
  echo "Case: 5"
  tail -n +4 test05.txt | work/a2-ece650/a2-ece650 > stdout 2>&1 &
  sleep 1
  kill $! > /dev/null 2>1
  if [ $? -eq 0 ]; then
    echo "@@@@@Program can not stop at EOF, or runs more than 1 second."
  else
    check_case_5
  fi
  echo "Point: " $grade

  echo "###########################################"
  echo "Case: 6"
  tail -n +4 test06.txt | work/a2-ece650/a2-ece650 > stdout 2>&1 &
  sleep 1
  kill $! > /dev/null 2>1
  if [ $? -eq 0 ]; then
    echo "@@@@@Program can not stop at EOF, or runs more than 1 second."
  else
    check_case_6
  fi
  echo "Point: " $grade

  echo "###########################################"
  echo "Case: 7"
  tail -n +4 test07.txt | work/a2-ece650/a2-ece650 > stdout 2>&1 &
  sleep 1
  kill $! > /dev/null 2>1
  if [ $? -eq 0 ]; then
    echo "@@@@@Program can not stop at EOF, or runs more than 1 second."
  else
    check_case_7
  fi
  echo "Point: " $grade

done
