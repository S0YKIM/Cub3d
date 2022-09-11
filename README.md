<div align="center">
  <img src="https://github.com/S0YKIM/Cub3d/blob/main/img/cube.jpg" height="128px" alt="cub3d" >
  <h1>Cub3D</h1>
  <p> Simple first-person 3d game with raycasting </p>
</div>
</br>

## 🎬 Preview
![](https://github.com/S0YKIM/Cub3d/blob/main/img/simulation.gif?raw=true)
</br></br></br>

## 🚀 Contributers
[🍀 sokim](https://github.com/S0YKIM) | [ 🔮 younjkim](https://github.com/objectio)

[🔗 노션 정리](https://pouncing-elbow-0a4.notion.site/Cub3d-398cfcddc5cd4725a88dba8f2b59251b)

</br>

## 🚧 Structure
```
./
├── includes/		# header files
├── libs/		# library files
│   ├── libft
│   ├── gnl
│   └── mlx
├── srcs/		# source files
│   ├── dda/            # raycasting functions
│   ├── exit/           # exit functions
│   ├── init/           # initialization functions
│   ├── map/            # map functions
│   ├── math            # calculating funtions
│   └── mlx/	       	# rendering functions
├── srcs_bonus/		# source files for bonus
├── maps/               # test map files
├── img/                # images for README
├── textures/           # images for wall texturing
└── Makefile
```

</br>

## ❓ Usage

### 🖐️ Clone
```
$ git clone https://github.com/S0YKIM/Cub3d
```

### 🖐️ Compile
```
$ make
```
```
$ make bonus  # minimap added to basic mode
```

### 🖐️ Execute
```
$ ./cub3D [path to .cub file]
```


### 🖐️ Play
```
  W
A S D  Press these keys to move player  
```
```
<- ->  Press these keys to rotate player  
```

</br>

## 🌊 Flowchart
![flowchart](https://github.com/S0YKIM/Cub3d/blob/main/img/program%20process.png?raw=true)

</br>
</br>

## 👭 Developing Process

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
- 맵이 벽으로 둘러쌓여 있는지 유효성 검사
#### To-do
- 플레이어 위치가 맵 컨텐츠 밖에 위치한 경우 에러 처리
- mlx 이용하여 새로운 창 띄우고, 마우스로 x 버튼 누르거나 esc 로 종료
- 이미지 화면에 연속적으로 띄우기(loop)

### 9월 2일(금)
#### Done
- 플레이어 위치가 맵 컨텐츠 밖에 위치한 경우 에러 처리
- mlx 이용하여 새로운 창 띄우고, 마우스로 x 버튼 누르거나 esc 로 종료
- 이미지 화면에 연속적으로 띄우기(loop)
- 회전변환행렬 이용하여 벡터 회전시키는 함수 구현
- 맵 데이터로부터 초기 플레이어 위치, 방향벡터, 카메라평면벡터 세팅

#### To-do
- W, A, S, D, 양쪽 화살표 키 이벤트 발생 시 플레이어 위치와 시점 조작
- DDA 알고리즘 이용하여 벽과 카메라 평면 사이 수직 거리 계산
- 맵 모양대로 텍스처 파일 적용하여 화면에 렌더링

### 9월 4일(일)
#### Done
- W, A, S, D, 양쪽 화살표 키 이벤트 발생 시 플레이어 위치와 시점 조작
- 벽과 벽 사이로 플레이어가 통과하지 못하도록 방지
- 프레임 그려주는 함수 구현
- floor, ceiling 색 레이어 적용
#### To-do
- DDA 알고리즘 이용하여 벽과 카메라 평면 사이 수직 거리 계산

### 9월 5일(월)
#### Done
- DDA 알고리즘 이용하여 벽과 카메라 평면 사이 수직 거리 계산
- 광선과 충돌한 벽면의 방향 알아내기
- 텍스처 대신 임의의 색상 이용하여 벽 렌더링(Untextured raycasting)
#### To-do
- 조작키를 눌러도 플레이어가 움직이지 않는 문제 해결
- 텍스처링 구현(Textured raycasting)

### 9월 6일(화)
#### Done
- W, A, S, D 를 누르면 플레이어가 움직이도록 문제 해결
- 화살표 키를 누르면 플레이어가 회전하도록 문제 해결
- 매번 루프가 실행될 때마다 프레임을 그리도록 구현
#### To-do
- 화면에 벽이 제대로 그려지지 않는 문제 해결
- 텍스처링 구현(Textured raycasting)

### 9월 7일(수)
#### Done
- 플레이어 초기 스폰이 'W' 또는 'E'일 때의 버그 해결
- 처음에 'W'키를 누르면 뒤로 가고 'S'키를 누르면 앞으로 가는 문제 해결
- 조작키를 누르면 누를수록 벽의 높이가 달라지는 현상 해결
#### To-do
- 텍스처 적용한 벽 렌더링

### 9월 8일(목)
#### Done
- 텍스처 적용한 벽 렌더링
- 존재하지 않는 텍스처 파일 사용 시 에러 처리
#### To-do
- 벽 이미지가 대각선으로 렌더링 되는 문제 해결
- 플레이어가 움직이면 벽 이미지도 함께 바뀌는 현상 해결
- 보너스 사항 중 미니맵 구현
- 최종 제출하기 전에 주의사항 점검 및 테스트

### 9월 9일 (금)
#### Done
- 미니맵 구현
- 맵 컨텐츠 안에 정의되지 않은 문자가 들어있는 경우 에러 처리
- 맵 파일 구성 요소들 사이 공백 문자가 여러개 들어있어도 스킵하고 유효하게 처리
- 샘플 맵파일 추가, 노미네트 검사, 최종 테스트
#### To-do
- 평가
