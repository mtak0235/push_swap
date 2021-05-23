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



```
 def A_to_B(r)
	if r < 3
		적절히 정렬
		return
	스택A 원소 중에서 "적절한" 피봇을 2개 선택한다
	for r개의 원소에 대해서
		if (스택A의 top) >= 피봇[큰것]
			ra명령으로 뒤로 넘긴다
			ra호출횟수++
		else
			pb명령으로 b로 보낸다
			pb호출횟수++
			if (스택B의 top) >= 피봇 [작은것]
				rb명령으로 뒤로 넘긴다
				rb호출횟수++
	for ra호출횟수, rb호출횟수
		rrr호출 #[3]과 [2]를 스택 앞으로 가져온다
	A_to_B(ra호출 횟수) #[3]
	B_to_A(rb호출 횟수) #[2]
	B_to_A(pb호출 횟수 - rb 호출 횟수) #[1]

def B_to_A(r)
	if r < 3
		적절히 정렬/pa로 보내기
		return
	스택B 원소 중에서 "적절한" 피봇을 2개 선택한다
	for r개의 원소에 대해서
		if (스택B의 top) < 피봇[작은것]
			rb명령으로 뒤로 넘긴다
			rb호출횟수++
		else
			pa명령으로 a로 보낸다
			pa호출횟수++
			if (스택B의 top) >= 피봇 [큰것]
				ra명령으로 뒤로 넘긴다
				ra호출횟수++
	A_to_B(pa호출횟수 - ra호출횟수) #[3]
	for ra호출횟수, rb호출횟수
		rrr호출 #[1]과 [2]를 스택 앞으로 가져온다
	A_to_B(rb호출횟수) #[2]
	B_to_A(ra호출횟수) #[1]