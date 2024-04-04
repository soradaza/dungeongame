// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyBasicCharacter.h"
#include "GameFramework/Actor.h"
#include "MyTestGameCharacter.generated.h"

/**
 * 
 */
UCLASS()
class DEAWARD_TEST_API AMyTestGameCharacter : public AMyBasicCharacter
{
	GENERATED_BODY()
		AMyTestGameCharacter();

	virtual void PostInitializeComponents()override;



protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)override;
	void MoveForward(float value);
	void MoveRight(float value);

private:
	class UAIPerceptionStimuliSourceComponent* stimulus;
	void setup_stimulus();

};
