// Fill out your copyright notice in the Description page of Project Settings.


#include "ChangeMesh.h"
#include "characterpawn.h"

// Sets default values
AChangeMesh::AChangeMesh()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetGenerateOverlapEvents(true);
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AChangeMesh::OnComponentBeginOverlap);

}

// Called when the game starts or when spawned
void AChangeMesh::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChangeMesh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChangeMesh::OnComponentBeginOverlap(UPrimitiveComponent * OverlappedComp,
	AActor * OtherActor,
	UPrimitiveComponent * OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult & SweepResult)
{

	Acharacterpawn* character = Cast<Acharacterpawn>(OtherActor);
	//UE_LOG(LogTemp, Warning, TEXT("Overlap CALLED"));
	if (character)
	{
		character->VisibleComponent = CustomUserValue;
		//character.
		//character->
		//GetWorld()->GetFirstPlayerController()->GetPawn()->SetActorLocation(CustomUserValue);
		//UE_LOG(LogTemp, Warning, TEXT("Overlap CALLED %s"), Cast<String>(character->GetName()));
		//character->SetActorLocation(CustomUserValue);
		//character->SetActorLocationAndRotation(CustomUserValue, character->GetActorRotation());
	}
}