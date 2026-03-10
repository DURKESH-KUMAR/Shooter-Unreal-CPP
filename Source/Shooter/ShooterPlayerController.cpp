#include "ShooterPlayerController.h"
#include "TimeManager.h"

void AShooterPlayerController::GameHasEnded(class AActor *EndGameFocus,bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus,bIsWinner);
    UE_LOG(LogTemp,Warning,TEXT("We have finished"));
    GetWordlTimerManager().SetTimer(RestartTimer,this,&APlayerController::RestartLevel,RestartDelay);
}
