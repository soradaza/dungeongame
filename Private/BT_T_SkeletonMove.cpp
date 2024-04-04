// Fill out your copyright notice in the Description page of Project Settings.


#include "BT_T_SkeletonMove.h"

EBTNodeResult::Type UBT_T_SkeletonMove::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    AMyEnemyAIController* Controller = Cast<AMyEnemyAIController>(OwnerComp.GetAIOwner());
    if (Controller == nullptr)
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "Controller is null");
        return EBTNodeResult::Failed;
    }

    ACharacter* Parent = Controller->GetCharacter();
    if (Parent == nullptr)
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "Parent is null");
        return EBTNodeResult::Failed;
    }

    UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
    if (!BlackboardComp)
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "Blackboard is null");
        return EBTNodeResult::Failed;
    }

    AAwardCharacter2* Target = Controller->GetPlayerActorKey();
    if (Target == nullptr)
    {
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "Target is null");
        return EBTNodeResult::Failed;
    }

    float Distance = Parent->GetDistanceTo(Target);

    if (Controller->MoveToActor(Target, 300) == EPathFollowingRequestResult::RequestSuccessful)
    {
        return EBTNodeResult::Succeeded;
    }
    return EBTNodeResult::Failed;
	//return EBTNodeResult::Type();
}
