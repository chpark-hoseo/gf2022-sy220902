#include "main.h"


const int SCREEN_WIDTH = 1024; // 화면 가로 길이
const int SCREEN_HEIGHT = 576; // 화면 세로 길이

// SDL을 초기화하고 윈도우를 생성한다
bool init();

// 미디어를 불러온다
bool loadMedia();

// 미디어를 해제하고 SDL을 종료한다
void close();

// 액자, Window (SDL_Window 구조체를 가리키는 포인터)
SDL_Window* gWindow = NULL;

// 그림, 윈도우에 포함될 Surface, 그래픽 메모리. Surface위에 그림을 그린다
SDL_Surface* gScreenSurface = NULL;

// 불러와서 화면에 출력할 이미지를 가리켜줄 변수
SDL_Surface* gHelloWorld = NULL;

bool init()
{
    // 성공 / 실패 플래그 변수 만들기
    bool success = true;

    // SDL 초기화
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError()); // SDL 초기화 실패했을 경우 에러 메시지
        success = false; // SDL 초기화에 실패했으면 플래그 변수로 표시해줌
    }
    else
    {
        // 윈도우 생성하기
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL) // 윈도우 생성에 실패했다면 SDL_CreateWindow는 NULL을 반환한다
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError()); // 윈도우 생성 실패했을 경우 에러 메시지
            success = false; // 윈도우 생성에 실패했으면 플래그 변수로 표시해줌
        }
        else
        {
            // gScreenSurface를 gWindow에 연결시켜줌
            // 윈도우에 포함된 surface를 잡는다
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }

    return success; // 함수 init은 자신의 성공 여부 플래그 변수를 true / false로 반환
}

bool loadMedia()
{
    // 성공 / 실패 플래그 변수 만들기
    bool success = true;

    gHelloWorld = SDL_LoadBMP("/Users/Admin/Documents/GitHub/gf2022-sy220902/assets/background.BMP");
    if (gHelloWorld == NULL) // gHelloWorld에 제대로 이미지가 로드되지 않았는지 체크
    {
        printf("Unable to load image %s! SDL Error: %s\n", "assets/background.BMP", SDL_GetError());
        success = false;
    }

    return success; // 함수 loadMedia는 자신의 성공 여부 플래그 변수를 true / false로 반환
}

void close()
{
    // surface를 할당 해제시킨다(?)
    SDL_FreeSurface(gHelloWorld);
    gHelloWorld = NULL; // 포인터 변수가 NULL을 가리키게 해주기

    // 윈도우 삭제
    SDL_DestroyWindow(gWindow);
    gWindow = NULL; // 포인터 변수가 NULL을 가리키게 해주기

    // SDL 서브시스템들을 종료시킨다
    SDL_Quit();

}



int main(int argc, char* argv[])
{
    // SDL을 시작하고 윈도우를 생성하기
    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        // 사용자가 게임을 종료했는지 아닌지 확인하는 플래그 변수
        // false인 동안 메인 루프가 돌아가고 있다
        bool quit = false;

        // SDL_Event 선언. 키 입력, 마우스 움직임 등을 뜻한다
        SDL_Event e;

        // 게임 종료 플래그 변수인 quit이 false인 동안,
        while (!quit)
        {
            // 이벤트 루프. 이벤트 큐가 empty가 될 때까지 계속 처리한다
            // 키 입력, 마우스 움직임 등을 입력받으면 이벤트가 이벤트 큐로 들어간다
            // SDL_PollEvent를 호출해 이벤트 대기열에서 가장 최근 이벤트를 가져와 이벤트 데이터를 함수에 전달한 SDL_Event에 넣는다
            // 큐가 empty 상태가 되면 SDL_PollEvent는 0을 리턴, e.type == SDL_QUIT으로 x버튼을 활성화시킨다.
            while (SDL_PollEvent(&e) != 0)
            {
                if (e.type == SDL_QUIT)
                {
                    quit = true;
                }
            }
        }


        // 미디어 불러오기
        if (!loadMedia())
        {
            printf("Failed to load media!\n");
        }
        else
        {
            // 이미지 적용하기
            // SDL_BlitSurface를 이용해 로드된 surface를 스크린 surface 위에 blit한다.
            // Blit은 비트들을 그래픽 메모리에서 다른 곳으로 복사하는 것을 뜻한다.
            // (소스 이미지, ?, 이미지들의 목적지, ?)
            // 백 버퍼로 렌더링 된다.
            SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

            // Surface를 업데이트한다.
            // SDL_UpdateWindowSurface를 모든 blit이 끝날 때마다 호출할 필요 없이
            // 현재 프레임의 모든 blit 작업이 끝난 후 호출하면 된다.
            SDL_UpdateWindowSurface(gWindow);

        }
    }

    
    
    // 프로그램을 종료한다.
    close();
    
    return 0;
}
