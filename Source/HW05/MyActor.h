// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class HW05_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

	void MoveActor();
	void TurnActor();
	void TriggerEvent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	int32 MoveCount = 0;
	int32 EventCount = 0;
	float TotalDistance = 0.f;
	
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
