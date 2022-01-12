class FileSystem(defaultdict):

    def __init__(self):
        super(FileSystem, self).__init__(FileSystem)
        self.content = ''

    def ls(self, path: str) -> List[str]:
        fs = self.mkdir(path)
        return path.rsplit('/', 1)[-1:] if fs.content else sorted(fs.keys())

    def mkdir(self, path: str) -> 'FileSystem':
      f = filter(None, path.split('/'))
      return reduce(dict.__getitem__, f, self)
        

    def addContentToFile(self, filePath: str, content: str) -> None:
      self.mkdir(filePath).content += content
        

    def readContentFromFile(self, filePath: str) -> str:
      return self.mkdir(filePath).content

