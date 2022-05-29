#ifndef __LPCORE_XML_NODE_H__
#define __LPCORE_XML_NODE_H__
#pragma once

#include "LupineCore/Xml/XmlBase.h"

namespace LupineCore
{
    class XmlText;
    class XmlUnknown;
    class XmlComment;
    class XmlElement;
    class XmlDocument;
    class XmlDeclaration;
    class XmlNode : public XmlBase
    {
    public:
        enum ENodeType
        {
            Document,
            Element,
            Comment,
            Unknown,
            Text,
            Declaration,
            NumOfTypes
        };

    public:
        LPCORE_API virtual ~XmlNode();
        inline String GetValue() const;
        inline void SetValue(const String &sValue);
        LPCORE_API void Clear();
        inline XmlNode *GetParent();
        inline const XmlNode *GetParent() const;
        inline XmlNode *GetFirstChild();
        inline const XmlNode *GetFirstChild() const;
        LPCORE_API XmlNode *GetFirstChild(const String &sValue);
        LPCORE_API const XmlNode *GetFirstChild(const String &sValue) const;
        inline XmlNode *GetLastChild();
        inline const XmlNode *GetLastChild() const;
        LPCORE_API XmlNode *GetLastChild(const String &sValue);
        LPCORE_API const XmlNode *GetLastChild(const String &sValue) const;
        inline XmlNode *IterateChildren(XmlNode *pPrevious);
        inline const XmlNode *IterateChildren(const XmlNode *pPrevious) const;
        inline XmlNode *IterateChildren(const String &sValue, XmlNode *pPrevious);
        inline const XmlNode *IterateChildren(const String &sValue, const XmlNode *pPrevious) const;
        LPCORE_API XmlNode *InsertEndChild(const XmlNode &cAddThis);
        LPCORE_API XmlNode *LinkEndChild(XmlNode &cAddThis);
        LPCORE_API XmlNode *InsertBeforeChild(XmlNode &cBeforeThis, const XmlNode &cAddThis);
        LPCORE_API XmlNode *InsertAfterChild(XmlNode &cAfterThis, const XmlNode &cAddThis);
        LPCORE_API XmlNode *ReplaceChild(XmlNode &cReplaceThis, const XmlNode &cWithThis);
        LPCORE_API bool RemoveChild(XmlNode &cRemoveThis);
        inline XmlNode *GetPreviousSibling();
        inline const XmlNode *GetPreviousSibling() const;
        LPCORE_API XmlNode *GetPreviousSibling(const String &sValue);
        LPCORE_API const XmlNode *GetPreviousSibling(const String &sValue) const;
        inline XmlNode *GetNextSibling();
        inline const XmlNode *GetNextSibling() const;
        LPCORE_API XmlNode *GetNextSibling(const String &sValue);
        LPCORE_API const XmlNode *GetNextSibling(const String &sValue) const;
        inline XmlElement *GetNextSiblingElement();
        LPCORE_API const XmlElement *GetNextSiblingElement() const;
        LPCORE_API XmlElement *GetNextSiblingElement(const String &sValue);
        LPCORE_API const XmlElement *GetNextSiblingElement(const String &sValue) const;
        inline XmlElement *GetFirstChildElement();
        LPCORE_API const XmlElement *GetFirstChildElement() const;
        inline XmlElement *GetFirstChildElement(const String &sValue);
        LPCORE_API const XmlElement *GetFirstChildElement(const String &sValue) const;
        inline ENodeType GetType() const;
        inline XmlDocument *GetDocument();
        LPCORE_API const XmlDocument *GetDocument() const;
        inline bool NoChildren() const;
        inline XmlDocument *ToDocument();
        inline const XmlDocument *ToDocument() const;
        inline XmlElement *ToElement();
        inline const XmlElement *ToElement() const;
        inline XmlComment *ToComment();
        inline const XmlComment *ToComment() const;
        inline XmlUnknown *ToUnknown();
        inline const XmlUnknown *ToUnknown() const;
        inline XmlText *ToText();
        inline const XmlText *ToText() const;
        inline XmlDeclaration *ToDeclaration();
        inline const XmlDeclaration *ToDeclaration() const;

    public:
        virtual XmlNode *Clone() const = 0;

    protected:
        XmlNode(ENodeType nType);
        XmlNode *Identify(const char *pszData, EEncoding nEncoding);

    protected:
        XmlNode *m_pParent;
        ENodeType m_nType;
        XmlNode *m_pFirstChild;
        XmlNode *m_pLastChild;
        String m_sValue;
        XmlNode *m_pPreviousSibling;
        XmlNode *m_pNextSibling;

    private:
        XmlNode(const XmlNode &cSource);
        XmlNode &operator=(const XmlNode &cSource);
    };

} // LupineCore

#include "LupineCore/Xml/XmlNode.inl"

#endif // __LPCORE_XML_NODE_H__
