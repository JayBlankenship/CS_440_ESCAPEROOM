// Fill out your copyright notice in the Description page of Project Settings.


#include "OnlineGameInstance.h"
#include "OnlineSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Engine/World.h"
#include "OnlineSessionSettings.h"


UOnlineGameInstance::UOnlineGameInstance()
{

}

void UOnlineGameInstance::Init()
{

	IOnlineSubsystem* subSystem = IOnlineSubsystem::Get();
	session = subSystem->GetSessionInterface();

	if (session.IsValid())
	{
		session->OnCreateSessionCompleteDelegates.AddUObject(this, &UOnlineGameInstance::OnCreateSessionComplete);
	}
	
}

void UOnlineGameInstance::OnCreateSessionComplete(FName serverName, bool succeeded)
{
	UE_LOG(LogTemp, Warning, TEXT("OnCreateSessionComplete: Succeeded [%d]"), succeeded);
	//GetWorld()->ServerTravel(TEXT("/Game/Escape_Room?listen"));
	GetWorld()->ServerTravel(TEXT("/Game/Main_Menu?listen"));
}

void UOnlineGameInstance::Host()
{
	UE_LOG(LogTemp, Warning, TEXT("Host"));
	FOnlineSessionSettings settings;
	if (session.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("Host sucess"));
	

		settings.bAllowInvites = true;
		settings.bIsLANMatch = true;
		settings.bAllowJoinInProgress = true;
		settings.NumPublicConnections = 4;
		settings.bUsesPresence = true;
		settings.bShouldAdvertise = true;

		
	}
	session->CreateSession(0, FName("EscapeRoomSession"), settings);

}

void UOnlineGameInstance::JoinServer()
{

}

void UOnlineGameInstance::EndServer()
{

}

