// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();

public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void Move(float Value);	

private:
	UPROPERTY(VisibleAnywhere, Category = "Tank Components")
	class UCameraComponent* m_Camera;

	UPROPERTY(VisibleAnywhere, Category = "Tank Components")
	class USpringArmComponent* m_SpringArm;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variables", meta = (AllowPrivateAccess = "true"))
	float m_fSpeed;
};
