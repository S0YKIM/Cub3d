# Cub3d

C project to make 3D game using ray-caster


[🍀 sokim](https://github.com/S0YKIM) | [ 🔮 younjkim](https://github.com/objectio)

[🔗 노션 정리](https://pouncing-elbow-0a4.notion.site/Cub3d-398cfcddc5cd4725a88dba8f2b59251b)

</br>

## 진행 기록

> 🍀 sokim | 🔮 younjkim

### 8월 21일(일)
#### Done
- 깃허브 레포 생성
- 커밋 컨벤션과 브랜치 네이밍 컨벤션 결정
- 레이캐스팅 개념 공부
#### To-do
- 선형대수, 회전변환행렬 공부
- 노션 서브젝트, 사용 가능 함수 정리 

### 8월 26일(금)
#### Done
- DDA 알고리즘(광선이 벽에 부딪히는 지점 구하기) 공부
- 광선의 시작점부터 벽까지의 이동거리 구하는 방법(유클리드 대신 수직거리 선택)
#### To-do
- 메이크파일, 헤더파일 작성
- 위에서 공부한 내용 코드로 작성

### 8월 28일(일)
#### Done
- 메이크파일, 헤더파일, 메인 작성
- 맵 파일 열기, 컨텐츠 유효성 검사
- map, player 구조체 만들고 초기화
- 맵 파싱하여 map, player 구조체 데이터 저장
#### To-do
- 맵 파일에서 texture, color 부분 파싱하여 저장
- 맵 파일에서 map 시작점과 종료 지점 구분하여 구조체에 저장
- 맵이 벽으로 둘어쌓여 있는지 유효성 검사

### 8월 29일(월)
#### Done
- 맵 파일에서 texture, color 부분 파싱하여 저장
- 맵 파일에서 map 시작점과 종료 지점 구분하여 구조체에 저장
- map 저장하기 전에 전제조건(texture, color)이 충족되었는지 유효성 검사
#### To-do
- texture, ceiling, floor 중복 검사
- 파일 마지막 읽어들이고 malloc 이 되지 않은 것을 free() 하면서 abort 뜨는 문제 해결
- 맵이 벽으로 둘어쌓여 있는지 유효성 검사

### 8월 30일(화)
#### Done
- texture, ceiling, floor, player 중복 검사
- double free 문제 해결, map[i][j]가 쓰레기값에 접근하는 문제 해결
- 파일에서 맵 부분만 추출하여 map 배열에 담기
- 맵 내용물 사이에 newline 이 끼어있는 경우 에러 처리
#### To-do

### 9월 2일(금)
#### Done
#### To-do
