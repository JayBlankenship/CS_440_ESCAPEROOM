// Fill out your copyright notice in the Description page of Project Settings.


#include "OnlineGameInstance.h"
#include "OnlineSubsystem.h"
#include "Kismet/GameplayStatics.h"
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
		session->OnFindSessionsCompleteDelegates.AddUObject(this, &UOnlineGameInstance::OnFindSessionsComplete);
		session->OnJoinSessionCompleteDelegates.AddUObject(this, &UOnlineGameInstance::OnJoinSessionComplete);
		session->OnEndSessionCompleteDelegates.AddUObject(this, &UOnlineGameInstance::OnEndSessionComplete);
	}
	
}

void UOnlineGameInstance::OnCreateSessionComplete(FName serverName, bool succeeded)
{
	
	GetWorld()->ServerTravel(TEXT("/Game/Escape_Room?listen"));
	
}

void UOnlineGameInstance::OnEndSessionComplete(FName name, bool flag)
{
	session->DestroySession(name);
}

void UOnlineGameInstance::OnJoinSessionComplete(FName name, EOnJoinSessionCompleteResult::Type Result)
{
	
	APlayerController* pController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (pController)
	{
		FString serverAddress = "";
		session->GetResolvedConnectString(name, serverAddress);
		if (serverAddress != "") {
			pController->ClientTravel(serverAddress, ETravelType::TRAVEL_Absolute);
		}
		
	}
}

void UOnlineGameInstance::OnFindSessionsComplete(bool success)
{

	if (success)
	{
		TArray<FOnlineSessionSearchResult> myResults = search->SearchResults;
		if (myResults.Num() > 0)
		{
			session->JoinSession(0, theServerName, myResults[0]);
		}
		
	}

}

void UOnlineGameInstance::Host(UPARAM(DisplayName = "Name")FString name)
{	
	
	UE_LOG(LogTemp, Warning, TEXT("Host with name: %s"), *name);
	FOnlineSessionSettings settings;
	theServerName.AppendString(name);

	if (session.IsValid())
	{

		settings.bAllowInvites = true;
		settings.bIsLANMatch = true;
		settings.bAllowJoinInProgress = true;
		settings.NumPublicConnections = 4;
		settings.bUsesPresence = true;
		settings.bShouldAdvertise = true;
	}
	session->CreateSession(0, theServerName, settings);

}

void UOnlineGameInstance::JoinServer()
{
	UE_LOG(LogTemp, Warning, TEXT("Join Server"));
	search = MakeShareable(new FOnlineSessionSearch());
	search->bIsLanQuery = true;
	search->MaxSearchResults = 500;
	search->QuerySettings.Set(SEARCH_PRESENCE, true, EOnlineComparisonOp::Equals);

	session->FindSessions(0, search.ToSharedRef());
}

void UOnlineGameInstance::EndServer()
{
	session->EndSession(theServerName);
}

