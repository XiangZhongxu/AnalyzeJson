// Copyright 2023 MrXiang, Inc. All Rights Reserved.


#include "JsonComponent.h"

// Sets default values for this component's properties
UJsonComponent::UJsonComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UJsonComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UJsonComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
FJsonLib::FJsonLib()
{
	JsonObject = MakeShared<FJsonObject>();
}

bool FJsonLib::JsonObjectFromString(const FString& Str)
{
	
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(Str);
	return FJsonSerializer::Deserialize(JsonReader, JsonObject);
}

bool UJsonComponent::GetJson(FString Josn,FJsonLib& OutJsonObject)
{
	OutJsonObject.JsonString=Josn;
	return OutJsonObject.JsonObjectFromString(Josn);
}

void UJsonComponent::GetJsonString(FJsonLib OutJsonObject,FString Key, FString& Json)
{
	Json=OutJsonObject.JsonObject->GetStringField(Key);
}

void UJsonComponent::GetJsonObj(FJsonLib OutJsonObject, FString Key, FJsonLib & JsonObject)
{
	FJsonLib linshi;
	// 获取Data
	JsonObject.JsonObject = OutJsonObject.JsonObject->GetObjectField(Key);
}

void UJsonComponent::GetJsonArray(FJsonLib OutJsonObject, FString Key,TArray<FString>& NewString)
{
	TArray<TSharedPtr<FJsonValue>> data = OutJsonObject.JsonObject->GetArrayField(Key);
	for(int i = 0; i < data.Num(); i++)
	{
		NewString.Add(data[i]->AsString());
	}
}