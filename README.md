# push_swap

매개변수가 숫자가 아니라면 "Error"출력
 숫자가 중복된다면 "
 int 범위를 벗어난다면 "
 매개변수가 없다면 화면에 아무거나 표시(?)
 ./push_swap 42". 프로그램에 아무 것도 표시하지 않아야
 ./push_swap 0 1 2 3". 프로그램에 아무 것도 표시되지 않아야
  ./push_swap 0 1 2 3 4 5 6 7 8 9".프로그램에 아무 것도 표시되지 않아야
 ARG="2 1 0"; ./push_swap $ARG | ./checker_OS $ARG 가 ok :선글라스:push_swap의 명령 목록 크기가 2 OR 3인 경우만 통과
 ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_OS $ARG 가 ok :선글라스:push_swap의 명령 목록 크기가 12 이하인 경우만 통과
  ARG=“<5 random values>"; ./push_swap $ARG | ./checker_OS $ARG :선글라스:push_swap의 명령 목록 크기가 12 이하인 경우만 통과
 ARG="<100 random values>"; ./push_swap $ARG | ./checker_OS $ARG - less than 700: 5 - less than 900: 4 - less than 1100: 3 - less than 1300: 2 - less than 1500: 1
 ARG="<500 random values>"; ./push_swap $ARG | ./checker_OS $ARG - less than 5500: 5 - less than 7000: 4 - less than 8500: 3 - less than 10000: 2 - less than 11500: 1