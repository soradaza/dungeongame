// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEnemyAIController.h"
#include "UObject/ConstructorHelpers.h"

AMyEnemyAIController::AMyEnemyAIController(const class FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
    BehaviorComp = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorComp"));
    BlackboardComp = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComp"));

    ConstructorHelpers::FObjectFinder<UBehaviorTree> BTFinder(TEXT("/Game/ThirdPersonCPP/AI/BT_Enemy"));
    BehaviorTree = BTFinder.Object;

    PlayerActorKeyName = "PlayerActor";
}

void AMyEnemyAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);
    BlackboardComp->InitializeBlackboard(*BehaviorTree->BlackboardAsset);

    BehaviorComp->StartTree(*BehaviorTree);
}

void AMyEnemyAIController::OnUnPossess()
{
    Super::OnUnPossess();
    BehaviorComp->StopTree();
}

void AMyEnemyAIController::SetPlayerActorKey(APawn* Goal)
{
    if (BlackboardComp)
    {
        BlackboardComp->SetValueAsObject(PlayerActorKeyName, Goal);
    }
}

AAwardCharacter2* AMyEnemyAIController::GetPlayerActorKey()
{
    if (BlackboardComp)
    {
        return Cast<AAwardCharacter2>(BlackboardComp->GetValueAsObject(PlayerActorKeyName));
    }
	return nullptr;
}

void AMyEnemyAIController::BeginPlay()
{
    Super::BeginPlay();
}
