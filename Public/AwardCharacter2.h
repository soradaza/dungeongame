// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AwardCharacter2.generated.h"

UCLASS()
class DEAWARD_TEST_API AAwardCharacter2 : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAwardCharacter2();

	UPROPERTY(EditDefaultsOnly, Category=Pawn)
	UAnimMontage* AttackAnim;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void Attack_Melee();


};
