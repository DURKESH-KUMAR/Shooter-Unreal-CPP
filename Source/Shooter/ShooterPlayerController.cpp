#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/PlayerController.h"

void AShooterPlayerController::BeginPlay()
{
    Super::BeginPlay();
    HUD = CreateWidget(this, HUDClass);   // removed UUserWidget*
    if (HUD != nullptr)
    {
        HUD->AddToViewport();
    }
}
void AShooterPlayerController::GameHasEnded(class AActor *EndGameFocus,bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus,bIsWinner);
    HUD->RemoveFromParent();
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



