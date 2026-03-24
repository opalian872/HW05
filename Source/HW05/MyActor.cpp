// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Engine/Engine.h"
// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	FVector ActorLocation = GetActorLocation();
	

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("Hello Unreal5"));
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, (TEXT("Actor: %s"), *GetName()));
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, (TEXT("Actor: %s"), ActorLocation.ToString()));
	}

	for (int32 i = 0; i < 10; i++)
	{
		MoveCount++;
		MoveActor();
		TurnActor();
		TriggerEvent();
		TotalDistance += FVector::Dist(ActorLocation, GetActorLocation());
		ActorLocation = GetActorLocation();
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Movestep: %d Location: %s Rotation: %s"), MoveCount, *ActorLocation.ToString(), *GetActorRotation().ToString()));
		UE_LOG(LogTemp, Warning, TEXT("Movestep: %d Location: %s Rotation: %s"), MoveCount, *GetActorLocation().ToString(), *GetActorRotation().ToString());
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Total Distance: %f Event triggered: %d / 10"), TotalDistance, EventCount));
	UE_LOG(LogTemp, Warning, TEXT("Total Distance: %f Event triggered: %d / 10"), TotalDistance, EventCount);
}


// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::MoveActor()
{
	int32 RandomX = FMath::RandRange(1, 100);
	int32 RandomY = FMath::RandRange(1, 100);
	int32 RandomZ = FMath::RandRange(1, 100);
	
	FVector NewLocation = GetActorLocation() + FVector(RandomX, RandomY, RandomZ);
	SetActorLocation(NewLocation);

	return;
}
void AMyActor::TurnActor()
{
	float RandomX = FMath::RandRange(0.f, 360.f);
	float RandomY = FMath::RandRange(0.f, 360.f);
	float RandomZ = FMath::RandRange(0.f, 360.f);

	SetActorRotation(FRotator(RandomX, RandomY, RandomZ));

	return;
}

void AMyActor::TriggerEvent()
{
	int32 RandomKey = FMath::RandRange(1, 100);
	if (RandomKey <= 50)
	{
		EventCount++;
		UE_LOG(LogTemp, Warning, TEXT("Event Triggered!"));
	}
}