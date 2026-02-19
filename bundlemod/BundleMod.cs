namespace bundlemod;

using System.Runtime.InteropServices;
using AssetsTools.NET;
using AssetsTools.NET.Extra;
using System;
using System.IO;
using System.Text;
using Microsoft.Win32.SafeHandles;

public class BundleMod
{
    static void LoadBundleFile(FileStream fs)
    {
        var manager = new AssetsManager();

        var bunInst = manager.LoadBundleFile(fs, true);
        var afileInst = manager.LoadAssetsFileFromBundle(bunInst, 0, false);
        var afile = afileInst.file;

        foreach (var texInfo in afile.GetAssetsOfType(AssetClassID.Texture2D))
        {
            var texBase = manager.GetBaseField(afileInst, texInfo);
            var name = texBase["m_Name"].AsString;
            var width = texBase["m_Width"].AsInt;
            var height = texBase["m_Height"].AsInt;
            Console.WriteLine($"Texture {name} is sized {width}x{height}");
        }
    }

    static void ReadFileFromSteam(FileStream fs) {
        byte[] b = new byte[1024];
        UTF8Encoding temp = new UTF8Encoding(true);
        int readLen;
        while ((readLen = fs.Read(b,0,b.Length)) > 0)
        {
            Console.WriteLine(temp.GetString(b,0,readLen));
        }
    }

    static void ReadFile(string filePath) {
        using (FileStream fs = File.OpenRead(filePath)) {
            ReadFileFromSteam(fs);
        }
    }

    static void ReadFileFromHandle(SafeFileHandle handle) {
        using (FileStream fs = new FileStream(handle, FileAccess.Read)) {
            ReadFileFromSteam(fs);
        }
    }

    [UnmanagedCallersOnly(EntryPoint = "hellorld")]
    public unsafe static void HellorldNative(IntPtr handle) {
        var safeHandle = new SafeFileHandle(handle, true);
        FileStream fs = new FileStream(safeHandle, FileAccess.Read);
        // var s = Marshal.PtrToStringUTF8((IntPtr)asd);
        LoadBundleFile(fs);
        // ReadFile(s);
        // ReadFileFromHandle();
    }
}
