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

package com.lasconic;

import org.qtproject.qt5.android.QtNative;

import java.lang.String;
import java.io.File;
import android.content.Intent;
import android.util.Log;
import android.net.Uri;
import android.content.ContentValues;
import android.provider.MediaStore.Images;
import android.content.Context;


public class QShareUtils
{
    protected QShareUtils()
    {
       //Log.d("lasconic", "QShareUtils()");
    }

    public static void share(String text, String url) {
        if (QtNative.activity() == null)
            return;
        Intent sendIntent = new Intent();
        sendIntent.setAction(Intent.ACTION_SEND);
        sendIntent.putExtra(Intent.EXTRA_TEXT, text + " " + url);
        sendIntent.setType("text/plain");
        QtNative.activity().startActivity(sendIntent);
    }

    public static void shareImage(String text, String url) {
        if (QtNative.activity() == null)
            return;
        Intent share = new Intent(Intent.ACTION_SEND);
        share.setType("image/jpeg");
/* TODO: set image title
        ContentValues values = new ContentValues();
        values.put(Images.Media.TITLE, text);
        values.put(Images.Media.MIME_TYPE, "image/jpeg");
        Uri uri = QtNative.activity().getContentResolver().insert(Images.Media.EXTERNAL_CONTENT_URI, values);
        share.putExtra(Intent.EXTRA_STREAM, uri);
*/
        File file = new File(url);
        share.putExtra(Intent.EXTRA_STREAM, Uri.fromFile(file));
        QtNative.activity().startActivity(Intent.createChooser(share, "Share Coloring Page"));
    }

}
