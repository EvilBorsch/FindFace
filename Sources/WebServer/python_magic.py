import face_recognition
from PIL import Image
from io import BytesIO
from urllib import request
import numpy as np
import sys

np.set_printoptions(threshold=np.inf, suppress=True)

try:
    url = sys.argv[1]
    data = request.urlopen(url).read()
    data = Image.open(BytesIO(data)).convert('RGB')
    array_img = np.array(data)
    faces_vectors = face_recognition.face_encodings(array_img)
    print(len(faces_vectors))
    for vector in faces_vectors:
        print(vector)

except Exception:
    print([])
