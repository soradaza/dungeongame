// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AwardCharacter2.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "MyEnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class DEAWARD_TEST_API AMyEnemyAIController : public AAIController
{
	GENERATED_BODY()

        AMyEnemyAIController(const class FObjectInitializer& ObjectInitializer);

    UBehaviorTreeComponent* BehaviorComp;

    UBlackboardComponent* BlackboardComp;

    /* Called whenever the controller possesses a character bot */
    virtual void OnPossess(class APawn* InPawn) override;

    virtual void OnUnPossess() override;

    UPROPERTY(EditDefaultsOnly, Category = AI)
        FName PlayerActorKeyName;

public:
    void SetPlayerActorKey(APawn* Goal);

    AAwardCharacter2* GetPlayerActorKey();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, Category = AI)
        class UBehaviorTree* BehaviorTree;

    FORCEINLINE UBehaviorTreeComponent* GetBehaviorComp() const { return BehaviorComp; }

    FORCEINLINE UBlackboardComponent* GetBlackboardComp() const { return BlackboardComp; }
};

	

