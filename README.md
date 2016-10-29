# TeseCpp
A C++/CLI port of text serializer library

## How to use?
```cpp
Address^ adr = gcnew Address("Main Road", 21, 42, 
             gcnew City("Berlin", State::UT, 12345));

Tese^ tese = gcnew Tese();
Stream^ writer = File::OpenWrite("test.txt");
tese->Serialize(adr, writer);
writer->Close();

Stream^ reader = File::OpenRead("test.txt");
adr = tese->Deserialize<Address^>(reader);
reader->Close();
```

## Example storing
```
# 02.09.2016 09:16:39
.street=Main Road
.number=21
.postal=42
.city.name=Berlin
.city.state=UT
.city.code=12345
```

## Example loading
![Image of Debugger](https://raw.githubusercontent.com/xafero/TeseCpp/master/doc/debugging.png)
