#pragma once

class TextBuffer
{
	char* data;
	unsigned length;

	void free();
	void copyFrom(const TextBuffer& other);

public:
	TextBuffer();
	TextBuffer(const char* str);

	TextBuffer(const TextBuffer& other);
	TextBuffer& operator=(const TextBuffer& other);
	
	~TextBuffer();

	void setContent(const char* str);
	void clear();

	const char* getRaw() const;
	unsigned getLength() const;

	void print() const;
};

