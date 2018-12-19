import bpy
import mathutils

bpy.context.scene.render.engine = 'octane'

for obj in bpy.data.objects:
    print(obj.name)

if "Cube" in bpy.data.meshes:
    mesh = bpy.data.meshes["Cube"]
    bpy.data.meshes.remove(mesh)

bpy.ops.import_scene.fbx(filepath="/home/xie/Documents/code/core3d/blender/women_b.fbx")

for obj in bpy.data.objects:
    print(obj.name)

for obj in bpy.data.objects:
    if obj.name[0:4] == "Mesh" or obj.name == "DrawCall_001":
        obj.location += mathutils.Vector((5, -3.5, 0))
        obj.location.z += 3
    if obj.name == "DrawCall_001":
        print(obj.active_material.specular_color)
        # print(dir(obj.octane_properties))

# bpy.data.scenes['Scene'].render.filepath = '/home/xie/Documents/code/core3d/blender/octane.jpg'
# bpy.ops.render.render( write_still=True )