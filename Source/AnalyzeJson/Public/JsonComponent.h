// Copyright 2023 MrXiang, Inc. All Rights Reserved.


#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "JsonComponent.generated.h"

USTRUCT(BlueprintType, meta = (DisplayName = "AnalyzeJson"))
struct  FJsonLib
{
	GENERATED_BODY()
public:
	FJsonLib();
	FString JsonString;
	TSharedPtr<FJsonObject> JsonObject;

	bool JsonObjectFromString(const FString& Str);
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ANALYZEJSON_API UJsonComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UJsonComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,FActorComponentTickFunction* ThisTickFunction) override;

public:
	FJsonLib NewFJsonLib;
	//转换
	UFUNCTION(BlueprintCallable,Category="AnalyzeJson")
	bool GetJson(FString Json,FJsonLib& OutJsonObject);
	//获取对象指定的Key
	UFUNCTION(BlueprintCallable,Category="AnalyzeJson")
	void GetJsonString(FJsonLib OutJsonObject,FString Key,FString& Json);
	//获取对象中的对象
	UFUNCTION(BlueprintCallable,Category="AnalyzeJson")
	void GetJsonObj(FJsonLib OutJsonObject,FString Key,FJsonLib & JsonObject);
	UFUNCTION(BlueprintCallable,Category="AnalyzeJson")
	void GetJsonArray(FJsonLib OutJsonObject,FString Key,TArray<FString>& NewString);
};
