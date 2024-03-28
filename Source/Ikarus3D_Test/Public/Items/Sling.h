// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Sling.generated.h"

UCLASS()
class IKARUS3D_TEST_API ASling : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASling();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UCameraComponent* ViewCamera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UBillboardComponent* MyBillboardComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* MyStaticMeshComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* MyArrowComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USceneComponent* DefaultSceneRoot;

};
