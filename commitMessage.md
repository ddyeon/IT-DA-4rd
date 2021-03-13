# 커밋 메시지 작성법

이 Repository에서는 커밋 메시지의 카테고리를 크게 3가지로 본다.

> C : Create

> U : Update

> D : Delete

일반적으로 CLI를 통해서 깃에 커밋 명령어를 전달하는 데, 다음과 같다.

> `git commit -m "커밋 메시지"`

여기서는 커밋 메시지에 들어갈 규칙에 대해서 설명하도록 하겠다.

## Type : C

파일을 만들 때 사용한다.

> Create 종류 문제번호 이름 

위와 같이 작성하면 된다.

여기서 종류에 들어갈 것은 `HW` `STD` 두 개이며 

HW는 과제를 의미하며 STD는 스터디 시간 중 푸는 문제를 의미한다.

ex) git commit -m "Create HW 1000 전진관"



## Type : U

문제를 다시 풀었거나, 무언가 실수가 있어서 수정했을 경우 사용한다.

> Update 수정한 이유(짧게)

ex) git commit -m "Update 파일 이름 수정"

ex) git commit -m "Update 풀이 수정"

어떤 부분을 어떻게 수정했는지 더 자세하게 적고 싶다면 줄을 바꾸고 내용을 작성하도록 한다.

ex)
```
git commit -m "Update 풀이 수정

이분 탐색 문제로 접근하고 풀어서 틀렸습니다를 받았지만, DP 방식으로 접근해서 문제를 풀 수 있었습니다."
```

## Type : D

파일을 삭제하는 경우 사용한다.

> Delete 파일 이름

ex ) git commit -m "Delete BOJ1001_전진관.java"

삭제를 진행할 경우 왜 삭제했는지 이유를 내용에 작성하도록 한다.

