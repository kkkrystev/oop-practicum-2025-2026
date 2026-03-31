#include "TextBuffer.h"
#include <iostream>
#include <cstring>

void TextBuffer::free()
{
	delete[] data;
	data = nullptr;
	length = 0;
}

void TextBuffer::copyFrom(const TextBuffer& other)
{
	length = other.length;
	data = new char[length + 1];
	strcpy_s(data, length + 1, other.data);
}

TextBuffer::TextBuffer()
	: data(new char[1] {'\0'}), length(0) {}

TextBuffer::TextBuffer(const char* str)
{
	if (!str) {
		data = new char[1] {'\0'};
		length = 0;
	}
	else {
		length = std::strlen(str);
		data = new char[length + 1];
		strcpy_s(data, length + 1, str);
	}
}

TextBuffer::TextBuffer(const TextBuffer& other)
{
	copyFrom(other);
}

TextBuffer& TextBuffer::operator=(const TextBuffer& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

TextBuffer::~TextBuffer() {
	free();
}

void TextBuffer::setContent(const char* str) {
	free();

	if (!str) {
		data = new char[1] {'\0'};
		length = 0;
		return;
	}

	length = std::strlen(str);
	data = new char[length + 1];
	strcpy_s(data, length + 1, str);
}

void TextBuffer::clear() {
	free();
	data = new char[1] {'\0'};
}

const char* TextBuffer::getRaw() const {
	return data;
}

unsigned TextBuffer::getLength() const {
	return length;
}

void TextBuffer::print() const {
	std::cout << data << '\n';
}