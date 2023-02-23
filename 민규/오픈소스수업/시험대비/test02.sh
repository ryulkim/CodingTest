set -o| grep ignoreeof // ignoreeof 켜짐
type -a kill //kill의 가리키는 곳 나타냄
alias kill='echo "hello"' //kill 재정의
unalias kill //정의 취소
sleep 1 & sleep 1 & sleep 1 // 3초 지남

시스템에서는 0이 true 나머지 false 

ls ~ && cat ~ // ls 성공하면 cat 실행, || 실패했을시

wc 0< users //주어지는 바이트 문자 단어, 줄 라인수 출력 , bc는 리눅스 시스템 전용계산기 실행 가능
sort 0< users
head -n 3 0< users
tail -n 2 0< users

cat 1>> log1.txt //log1.txt 내용삼입 모드
echo hi 1>> log1.txt // hi를 삽입

bc -l < log2.txt > result.txt : log2의 내용 계산해서 result에 저장

///////////////////////

input, output 둘 다 있는 거 : cat, cut ,awk

cat log1.txt | head -n 2 // 2번 째 줄 까지만 읽음

cat /proc/meminfo | grep Buffer //Buffer의 내용  catch 해서 잡아옴


cat /proc/meminfo | grep BUffer | tr -d [:blank:] | cut -d: -f2 //두번째 줄을 읽음 -d뒤에 붙은걸 기준으로 자른다
cat /proc/meminfo | awk '$1~"Buffer"{print $2}' //첫번째 내용이 Buffer이면 2번째 라인 출력

awk '$3~"Inode"{print $4}' //예제 문제

#!bin/bash //Shabang
echo $4 ${15} $6 //10번째 index 부터는 중괄호 필요 $0 : 현재 셀 스크립트 , $# positional parameter , $* all positional parameter, $? 최근에 실행된 커맨드
read -p "enter" name // read 입력받아서 name에 저장

#############################3

[ $var -le 3 ] && echo $var || echo "nono" // var가 3보다 작거나 같으면 &&뒤의 내용 실행

[ -e name ] : name이 존재하는 지, -f : file , -d : dir , -z : 스트링 길이가 0 , -n : string 길이가 0이 아닌 경우


if []
then
elif
then
else
fi


[ $op = add ]
[ $op = sub ]

case word in
pattern )
commands ;;
esac

