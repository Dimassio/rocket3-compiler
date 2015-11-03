#pragma once

class IVisitor;

// Корневой интерфейс программы
class IProgram {
public:
	virtual ~IProgram()
	{
	}
	virtual void Accept( IVisitor* ) const = 0;
};

// Главный класс
class IMainClass {
public:
	virtual ~IMainClass()
	{
	}
	virtual void Accept( IVisitor* ) const = 0;
};

// Список классов
class IClassDeclList {
public:
	virtual ~IClassDeclList()
	{
	}
	virtual void Accept( IVisitor* ) const = 0;
};

// Описание класса
class IClassDecl {
public:
	virtual ~IClassDecl()
	{
	}
	virtual void Accept( IVisitor* ) const = 0;
};

// Список объявлений переменных
class IVarDeclList {
public:
	virtual ~IVarDeclList()
	{
	}
	virtual void Accept( IVisitor* ) const = 0;
};

// Объявление переменной
class IVarDecl {
public:
	virtual ~IVarDecl()
	{
	}
	virtual void Accept( IVisitor* ) const = 0;
};

// Список методов класса
class IMethodDeclList {
public:
	virtual ~IMethodDeclList()
	{
	}
	virtual void Accept( IVisitor* ) const = 0;
};

// Метод класса
class IMethodDecl {
public:
	virtual ~IMethodDecl()
	{
	}
	virtual void Accept( IVisitor* ) const = 0;
};

// Список параметров
class IFormalList {
public:
	virtual ~IFormalList()
	{
	}
	virtual void Accept( IVisitor* ) const = 0;
};

class IFormalRest {
public:
	virtual ~IFormalRest()
	{
	}
	virtual void Accept(IVisitor*) const = 0;
};

class IFormalRestList {
public:
	virtual ~IFormalRestList()
	{
	}
	virtual void Accept(IVisitor*) const = 0;
};

// Тип
class IType {
public:
	virtual ~IType()
	{
	}
	virtual void Accept( IVisitor* ) const = 0;
};

// Последовательность команд
class IStatementList {
public:
	virtual ~IStatementList()
	{
	}
	virtual void Accept( IVisitor* ) const = 0;
};

// Одна команда (или блок)
class IStatement {
public:
	virtual ~IStatement()
	{
	}
	virtual void Accept( IVisitor* ) const = 0;
};

// Последовательность выражений (аргументы функции)
class IExpList {
public:
	virtual ~IExpList()
	{
	}
	virtual void Accept( IVisitor* ) const = 0;
};

// Арифметическое выражение
class IExp {
public:
	virtual ~IExp()
	{
	}
	virtual void Accept(IVisitor*) const = 0;
};

class IExpBinOperation {
public:
	virtual ~IExpBinOperation()
	{
	}
	virtual void Accept(IVisitor*) const = 0;
};

class IExpLength {
public:
	virtual ~IExpLength()
	{
	}
	virtual void Accept(IVisitor*) const = 0;
};

class IExpNewIntArray {
public:
	virtual ~IExpNewIntArray()
	{
	}
	virtual void Accept(IVisitor*) const = 0;
};

class IExpNumber {
public:
	virtual ~IExpNumber()
	{
	}
	virtual void Accept( IVisitor* ) const = 0;
};

class IExpNot {
public:
	virtual ~IExpNot()
	{
	}
	virtual void Accept(IVisitor*) const = 0;
};

class IExpNewCustomType {
public:
	virtual ~IExpNewCustomType()
	{
	}
	virtual void Accept(IVisitor*) const = 0;
};

class IExpRoundBrackets {
public:
	virtual ~IExpRoundBrackets()
	{
	}
	virtual void Accept(IVisitor*) const = 0;
};

class IExpSingle {
public:
	virtual ~IExpSingle()
	{
	}
	virtual void Accept(IVisitor*) const = 0;
};

class IExpSquareBrackets {
public:
	virtual ~IExpSquareBrackets()
	{
	}
	virtual void Accept(IVisitor*) const = 0;
};

class IExpMethodCall {
public:
	virtual ~IExpMethodCall()
	{
	}
	virtual void Accept(IVisitor*) const = 0;
};

class IExpId {
public:
	virtual ~IExpId()
	{
	}
	virtual void Accept(IVisitor*) const = 0;
};

class IExpRest {
public:
	virtual ~IExpRest()
	{
	}
	virtual void Accept( IVisitor* ) const = 0;
};

class IExpRestList {
public:
	virtual ~IExpRestList()
	{
	}
	virtual void Accept( IVisitor* ) const = 0;
};