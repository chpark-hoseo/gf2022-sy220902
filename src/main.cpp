#include "main.h"



int main(int argc, char* argv[])
{
    SDL_Window* window = NULL; // 액자, Window (SDL_Window 구조체를 가리키는 포인터)

    SDL_Surface* screenSurface = NULL; // 그림, 윈도우에 포함될 Surface, 그래픽 메모리. Surface위에 그림을 그린다

    const int SCREEN_WIDTH = 1920; // 화면 가로 길이
    const int SCREEN_HEIGHT = 1080; // 화면 세로 길이

    // SDL 초기화(어떤 서브 시스템을 초기화할지 정하는 매개변수)
    if (SDL_Init(SDL_INIT_VIDEO) < 0) // 오류가 생기면 SDL_Init은 -1을 리턴한다
    {
        printf("SDL을 초기화할 수 없습니다! SDL_Error: %s\n", SDL_GetError()); // 에러를 콘솔창에 출력
    }
    else
    {
        // 윈도우 만들기. 반환값은 SDL_Window 포인터. (윈도우의 이름(게임 이름), x 좌표,          y 좌표,                   가로 길이,     세로 길이,    생성flag(?))
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL) // 에러가 생기면 SDL_CreateWindow는 NULL을 리턴한다.
        {
            printf("윈도우를 생성할 수 없습니다! SDL_Error: %s\n", SDL_GetError()); // 에러를 콘솔창에 출력
        }
        else
        {
            // Surface와 Window를 연결하기. screenSurface가 window와 연결된 Surface가 되게 만든다
            // 반환값은 SDL_Surface 포인터인데, Window와 연결된 Surface다.
            // 이렇게 반환된 SDL_Surface의 경우, SDL_Window가 destroy되면 자동으로 같이 free()된다.
            screenSurface = SDL_GetWindowSurface(window);

            // surface를 하얗게 채운다(그림을 그릴 SDL_Surface 구조체의 포인터, 채울 직사각형을 표현하는 SDL_Rect 구조체의 포인터 또는 NULL(전체를 채움), 채울 색상)
            SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
        
            // SDL_FillRect 함수를 이용해서 바뀐 Surface를 Window에 갱신시켜준다. (갱신할 Window의 포인터)
            // 성공했다면 0, 실패했다면 음수를 반환한다.
            SDL_UpdateWindowSurface(window);

        
        }
    }

    // window의 메모리를 해제 (window가 해제되면 Surface도 같이 해제됨)
    SDL_DestroyWindow(window);

    // SDL 시스템의 종료
    SDL_Quit();


    return 0;
}
