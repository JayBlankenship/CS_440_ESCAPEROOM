// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PressurePlate.generated.h"


UCLASS()
class CS_440_ESCAPEROOM_API APressurePlate : public AActor
{
	GENERATED_BODY()
	
public:	

	// Sets default values for this actor's properties
	APressurePlate();

	UPROPERTY()
		USceneComponent* root;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* mesh;

	UPROPERTY(EditAnywhere)
		AActor* player;

	UPROPERTY(EditAnywhere)
		class UCapsuleComponent* collisionCapsule;

	UPROPERTY(EditAnywhere)
		UMaterialInstanceDynamic* daynamicM;

	FVector Location;  //store the items location

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	virtual void BeginOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);

	UFUNCTION()
		virtual void EndOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);
};
