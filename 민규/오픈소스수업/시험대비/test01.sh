var1=5
echo $var1
unset var1 //할당y해제

var1 = 10
export var2=50 //환경변수 선언
env | grep var2 //환경변수만 표시


pstree | grep bash
var3=10
export var4=20 // -n옵션 있을시 sub에서 나타나지 않음
echo $var3, $var4 //둘 다나옴

bash
pstree | grep bash //sub tree
echo $var3, $var4 //뒤에 것만 나옴
exit

////////////////


echo A{1,2}B //A1B A2B
echo {c..k} // c d ~ k
echo {1..10..2} //1 3 5 7 9
echo {a..z}{0..9} //a0 ~z9
echo {{A..Z} , {a..z}} //A ~ zsls

~ //부모 dir

var1=10
echo "hellovar1" // hellovar1
echo "hello${var1}" //hello10

unset var1
echo ${var1:-100} //100

echo "today $(date)" today ~날짜
c=$((a+b)) //a+b

echo "$a $b" //a,b에 저장된 값 출력
echo "$x $((x++)) $x" // x x x+1 // +가 왼쪽에 있으면 x x+1 x+1

ls test?.o // ?는 한글자 대체
ls *.[ch] // c또는 h로 끝나는 모든 파일 [^]일시는 미포함 예제


touch * -> 기존 파일들 생성
touch /* -> *의 특성 무시





