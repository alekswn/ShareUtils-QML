//=============================================================================
// Copyright (c) 2014 Nicolas Froment
// Copyright (c) 2015 Alexey Novikov

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//=============================================================================
#include "androidshareutils.h"

#include <QtAndroidExtras/QAndroidJniObject>

AndroidShareUtils::AndroidShareUtils(QQuickItem* parent) : PlatformShareUtils(parent)
{

}

void AndroidShareUtils::share(const QString &text, const QUrl &url)
{
    QAndroidJniObject jsText = QAndroidJniObject::fromString(text);
    QAndroidJniObject jsUrl = QAndroidJniObject::fromString(url.toString());
    QAndroidJniObject::callStaticMethod<void>("com/github/alekswn/shareutils_qml/QShareUtils",
                                       "share",
                                       "(Ljava/lang/String;Ljava/lang/String;)V",
                                       jsText.object<jstring>(), jsUrl.object<jstring>());
}
void AndroidShareUtils::shareImage(const QUrl &url)
{
    qDebug() << url.toString();
    QAndroidJniObject jsUrl = QAndroidJniObject::fromString(url.toString());
    QAndroidJniObject::callStaticMethod<void>("com/github/alekswn/shareutils_qml/QShareUtils",
                                       "shareImage",
                                       "(Ljava/lang/String;)V",
                                       jsUrl.object<jstring>());
}
void AndroidShareUtils::viewImage(const QUrl &url)
{
    qDebug() << url.toString();
    QAndroidJniObject jsUrl = QAndroidJniObject::fromString(url.toString());
    QAndroidJniObject::callStaticMethod<void>("com/github/alekswn/shareutils_qml/QShareUtils",
                                       "viewImage",
                                       "(Ljava/lang/String;)V",
                                       jsUrl.object<jstring>());
}

void AndroidShareUtils::installApp(const QString &appPackageName)
{
    qDebug() << appPackageName;
    QAndroidJniObject jsText = QAndroidJniObject::fromString(appPackageName);
    QAndroidJniObject::callStaticMethod<void>("com/github/alekswn/shareutils_qml/QShareUtils",
                                       "installApp",
                                       "(Ljava/lang/String;)V",
                                       jsText.object<jstring>());
}
