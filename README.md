# Algorithm

SWM 14기 METEOR 팀 코딩테스트 대비 알고리즘 스터디 (2023.06.01 ~ 2023.11.31)

Notion : https://www.notion.so/soma-meteor/1ca54de40dfe4ef897ce8dcda15c8887?pvs=4

# Rules
- 매주 월요일 백준, 프로그래머스 사이트의 문제가 게시됩니다.
  - 백준은 solved.ac 기준 실버 ~ 골드의 문제가, 프로그래머스는 Lv2 ~ Lv.3 문제가 선택됩니다.
  - `유형 별 풀이` 또는 `랜덤 유형 풀이` 의 두 가지 방식이 존재하며, 주차에 따라 다를 수 있습니다.  
- 주차 별 문제를 확인하고, 해당 주차의 토요일 23:59까지 PR을 완료해야합니다.
- 해당 주차의 일요일 23:59까지 Code Review 를 완료해야합니다.

# 과제 진행 방법
1. 본 Repository를 `fork`하고, `clone`합니다. 새로운 주차 폴더가 생겼을 경우 `pull` 또는 `fetch`를 진행합니다.   
2. fork한 저장소의 각 주차에 해당되는 폴더에 `플랫폼_문제번호_이름`의 소스코드를 `add`, `commit`, `push`합니다.   
   - `commit`은 문제마다 수행하며, `이름:플랫폼_문제번호` 로 커밋을 진행합니다.
3. 모든 문제를 풀고 주차 별 1번의 PR을 보낸 후, 다른 팀원의 Code Review를 기다립니다.   
   - 이 때 PR은 **[이름]N주차 과제 제출** 로 합니다.
4. Code Review 수행 시  
   - 코드 수정이 필요 없다면, `approve`를 선택합니다.
   - 필요하다면, `Request changes`를 선택합니다.
   - 라인 별 피드백을 활용해 code review를 진행합니다.

# Git branch Protection Rule
1. PR을 통해 모든 팀원들로부터 approve된 경우만 Algorithm:main 브랜치로 merge가 가능합니다.
   - 마지막으로 approve하는 사람이 해당 PR을 merge합니다.
2. 따라서, 담당 팀원의 Code Review 및 approve 처리를 반드시 수행해야 합니다.
