#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/PlayerController.h"


void AShooterPlayerController::GameHasEnded(class AActor *EndGameFocus,bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus,bIsWinner);
    UE_LOG(LogTemp,Warning,TEXT("We have finished"));
    if(bIsWinner)
    {
        UUserWidget* WinScreen=CreateWidget(this,WinScreenClass);
        if(WinScreen!=nullptr)
        {
            WinScreen->AddToViewport();
        }
        
    }else
    {
        UUserWidget* LoseScreen=CreateWidget(this,LoseScreenClass);
        if(LoseScreen!=nullptr)
        {
            LoseScreen->AddToViewport();
        }
    }
    GetWorldTimerManager().SetTimer(RestartTimer,this,&APlayerController::RestartLevel,RestartDelay);
}

