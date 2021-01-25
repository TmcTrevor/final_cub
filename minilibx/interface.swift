
import Cocoa



@_cdecl("mlx_get_screen_size")
public func mlx_get_screen_size_swift(_ mlxptr:UnsafeRawPointer, _ sizex:UnsafeMutablePointer<Int32>, _ sizey:UnsafeMutablePointer<Int32>) -> Int32
{
	/// let mlx:MlxMain = _mlx_bridge(ptr:mlxptr)
	sizex.pointee = Int32(NSScreen.main!.frame.size.width)
	sizey.pointee = Int32(NSScreen.main!.frame.size.height)
	return Int32(0)
}