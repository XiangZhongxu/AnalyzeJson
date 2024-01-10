# 解析Json
代码只有一个JsonComponent
## 使用方法
新建蓝图后添加组件 Json
组件有4个函数
1. GetJson
2. GetJsonString-通过KEy获取值
3. GetJsonObj-通过Key获取对象
4. GetJsonArray-通过Key获取数组

{
  "姓名": "张三",  
  "年龄": 25,  
  "城市": "北京",  
  "在校生": false,  
  "爱好": ["游泳", "阅读", "旅行"],  
  "地址": {  
    "省份": "北京市",  
    "区域": "朝阳区",  
    "街道": "建国路"  
  }  
}  

GetJson 输入Json对象返回FJsonLib类型

GetJsonString，输入FJsonLib和Key 返回对应字符串值。如输入姓名 返回张三

GetJsonObj，输入FJsonLib和Key 返回对应字符串值。如输入地址返回一个新的FJsonLib对象

GetJsonArray 输入FJsonLib和Key 返回对应字符串数组，如输入爱好，返回[游泳, 阅读, 旅行]
