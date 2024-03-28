// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Dots.generated.h"

UCLASS()
class IKARUS3D_TEST_API ADots : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADots();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	class UStaticMeshComponent* Dot;
	void DestroyActorDelayed();
	


};
