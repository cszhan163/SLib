/*
 *   Copyright (c) 2008-2019 SLIBIO <https://github.com/SLIBIO>
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in
 *   all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *   THE SOFTWARE.
 */

#ifndef CHECKHEADER_SLIB_SERVICE_CAPTCHA
#define CHECKHEADER_SLIB_SERVICE_CAPTCHA

#include "definition.h"

#include "../core/string.h"
#include "../graphics/image.h"
#include "../graphics/font.h"

namespace slib
{

	class SLIB_EXPORT Captcha
	{
	public:
		Captcha();
		
		SLIB_DECLARE_CLASS_DEFAULT_MEMBERS(Captcha)
		
	public:
		String getCode() const;
		String16 getCode16() const;

		void setCode(const StringParam& code);
		
		sl_uint32 getCodeLength() const;
		
		void setCodeLength(sl_uint32 length);
		
		String16 getCodeElements() const;
		
		void setCodeElements(const StringParam& codeset);
		
		String16 getInterferingElements() const;
		
		void setInterferingElements(const StringParam& elements);
		
		sl_uint32 getWidth() const;
		
		void setWidth(sl_uint32 width);
		
		sl_uint32 getHeight() const;
		
		void setHeight(sl_uint32 height);
		
		Ref<Font> getFont() const;
		
		void setFont(const Ref<Font>& font);
		
		void setBackgroundColor(const Color& background);

	public:
		Ref<Image> generate(String* outCode = sl_null);
		
	protected:
		Mutex m_lock;
		
		AtomicString16 m_code;
		AtomicString16 m_codeInput;

		Ref<Image> m_image;
		Ref<Bitmap> m_bitmap;
		
		sl_uint32 m_length;
		sl_uint32 m_width;
		sl_uint32 m_height;
		AtomicRef<Font> m_font;
		AtomicString16 m_codeset;
		AtomicString16 m_interferingElements;
		Color m_background;
		
	};
	
}

#endif
