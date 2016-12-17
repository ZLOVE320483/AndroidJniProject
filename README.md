# AndroidJniProject
此项目展示了java和C之间的互相调用，包括互相传递参数，各个类型的方法或者参数都有涵盖，非常适用于初学者。
###方法说明
  getStringFromNative：从C层获取一个字符串返回
  
  square：求int, float,double类型数值的平方
  
  greetings：传一个字符串给C层，C层回传另一个字符串给Java层
  
  getTwoArray：获取C层返回的一个二维数组
  
  nativeSetName：C层改变Java层某个属性的值
  
  doCallback：C层回调Java层方法
  
  nativeGetUser：C层生成Java层某个对象并返回
  
  printUserInfoAtNative：C层打印Java对象的属性值
  
  changeUserInfo：C层改变Java对象的属性值并返回
  
  nativeGetUserList：C层构造Java对象列表并返回
