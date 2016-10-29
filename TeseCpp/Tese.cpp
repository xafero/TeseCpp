
#include "stdafx.h"

#include "Tese.h"

String^ TeseCpp::Tese::Serialize(Object^ obj) 
{
	array<Byte>^ bytes;
	{
		MemoryStream^ mem = gcnew MemoryStream();
		Serialize(obj, mem);
		bytes = mem->ToArray();
		mem->Close();
	}
	return Encoding::UTF8->GetString(bytes);
}

generic <typename T>
T TeseCpp::Tese::Deserialize(Stream^ stream) 
{
	try {
		JavaProperties^ props = gcnew JavaProperties();
		props->Load(stream);
		return (T)DeserializeFields(emptyPrefix, props, T::typeid);
	} catch (IOException^ e) {
		throw gcnew TeseReadException(e);
	}
}

generic <typename T>
T TeseCpp::Tese::Deserialize(String^ text) 
{
	array<Byte>^ bytes = Encoding::UTF8->GetBytes(text);
	{
		MemoryStream^ mem = gcnew MemoryStream(bytes);
		return Deserialize<T>(mem);
	}
}

Object^ TeseCpp::Tese::DeserializeFields(String^ prefix, IDictionary^ props, Type^ type)
{
	try {
		Object^ obj = Activator::CreateInstance(type);
		array<FieldInfo^>^ fields = type->GetFields(BindingFlags::NonPublic | BindingFlags::Instance);
		for each (FieldInfo^ field in fields)
			DeserializeField(prefix, obj, field, props);
		return obj;
	} catch (Exception^ e) {
		throw gcnew TeseReadException(e);
	}
}

Void TeseCpp::Tese::DeserializeField(String^ prefix, Object^ obj, FieldInfo^ field, IDictionary^ props)
{
	try {
		String^ key = field->Name;
		String^ objKey = String::Format("{0}.{1}", prefix, key);
		Object^ val = props[objKey];
		if (val == nullptr) {
			if (FindLongerKey(props, objKey)) {
				field->SetValue(obj, DeserializeFields(objKey, props, field->FieldType));
			}
			return;
		}
		field->SetValue(obj, FromStr(val->ToString(), field));
	} catch (Exception^ e) {
		throw gcnew TeseReadException(e);
	}
}
		
bool TeseCpp::Tese::FindLongerKey(IDictionary^ props, String^ shortKey)
{
	for each (Object^ key in props->Keys)
		if (key->ToString()->StartsWith(shortKey, StringComparison::InvariantCulture))
			return true;
	return false;
}
		
Object^ TeseCpp::Tese::FromStr(String^ val, FieldInfo^ field)
{
	Type^ type = field->FieldType;
	if (type->IsEnum)
		return Enum::Parse(type, val);
	CultureInfo^ cult = CultureInfo::InvariantCulture;
	/*switch (type->Name) {
		case "Boolean":
			return Boolean.Parse(val);
		case "Byte":
			return Byte.Parse(val);
		case "Char":
			return Char.Parse(val);
		case "Single":
			return Single.Parse(val, cult);
		case "Double":
			return Double.Parse(val, cult);
		case "Int32":
			return Int32.Parse(val);
		case "Int16":
			return Int16.Parse(val);
		case "Int64":
			return Int64.Parse(val);
		case "BigInteger":
			return BigInteger.Parse(val, cult);
		case "Decimal":
			return decimal.Parse(val, cult);
		case "DateTime":
			return DateTime.Parse(val, cult).ToUniversalTime();
		case "String":
			return val;
		default:
			throw gcnew InvalidOperationException(type + " is not supported!");
	}*/
	throw gcnew InvalidOperationException(type + " is not supported!");
}

Void TeseCpp::Tese::Serialize(Object^ obj, Stream^ writer)
{
	try {
		JavaProperties^ props = gcnew JavaProperties();
		SerializeFields(emptyPrefix, obj, props);
		props->Store(writer, nullptr);
	} catch (IOException^ e) {
		throw gcnew TeseWriteException(e);
	}
}
		
Void TeseCpp::Tese::SerializeFields(String^ prefix, Object^ obj, IDictionary^ props)
{
	Type^ type = obj->GetType();
	array<FieldInfo^>^ fields = type->GetFields(BindingFlags::NonPublic | BindingFlags::Instance);
	for each (FieldInfo^ field in fields)
		SerializeField(prefix, obj, field, props);
}
		
Void TeseCpp::Tese::SerializeField(String^ prefix, Object^ obj, FieldInfo^ field, IDictionary^ props)
{
	try {
		String^ key = field->Name;
		Object^ val = field->GetValue(obj);
		String^ objKey = String::Format("{0}.{1}", prefix, key);
		try {
			props[objKey] = ToStr(val, field);
		} catch (InvalidOperationException^) {
			SerializeFields(objKey, val, props);
		}
	} catch (Exception^ e) {
		throw gcnew TeseWriteException(field, e);
	}
}
		
String^ TeseCpp::Tese::ToStr(Object^ value, FieldInfo^ field)
{
	Type^ type = field->FieldType;
	if (type->IsEnum)
		return value->ToString();
	CultureInfo^ cult = CultureInfo::InvariantCulture;
	String^ name = type->Name;
	if (name->Equals("DateTime")) 
		return ((DateTime)value).ToString("yyyy-MM-dd'T'HH:mm:ss.fffzzz");
	if (name->Equals("Single"))
		return ((float)value).ToString(cult);
	if (name->Equals("Double"))
		return ((double)value).ToString(cult);
	if (name->Equals("Decimal"))
		return ((Decimal)value).ToString(cult);
	if (Array::BinarySearch(gcnew array<String^> { "Boolean","BigInteger","Int64",
		"Char","Int32","Byte","Int16","String" }, name) >= 0)
		return value->ToString();
	throw gcnew InvalidOperationException(type + " is not supported!");
}
