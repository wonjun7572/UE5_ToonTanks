// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* m_CapsuleComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* m_BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* m_TurretMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* m_ProjectileSpawnPoint;

	// 인스턴스 -> 디테일 패널, 디폴트 -> 블루프린트의 디테일 패널
	
	// EditAnywhere : 어디서든 편집가능 (인스턴스, 디폴트)
	// EditInstanceOnly : 인스터스에서만 편집가능. 
	// EditDefaultsOnly : 디폴트에서만 편집가능. 

	// VisibleAnywhere : 어디서든 보인다 (인스턴스, 디폴트)
	// VisibleInstanceOnly : 인스터스에서만 보인다. 
	// VisibleDefaultsOnly : 디폴트에서만 보인다.

	// BlueprintReadOnly : 블루프린트의 이벤트 그래프에서 읽기만 가능
	// BlueprintReadWrite :  블루프린트의 이벤트 그래프에서 편집 가능

	// 카테고리 추가.

	// meta = (AllowPrivateAccess = "true") 
	// 원래 변수가 private면 이벤트 그래프에서 편집이 되는 것이 불가능하지만
	// 이 구문을 사용해서 private여도 허락해줄수있다.
};
