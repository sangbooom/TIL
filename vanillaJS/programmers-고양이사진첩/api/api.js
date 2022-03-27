const baseUrl =
  "https://zl3m4qq0l9.execute-api.ap-northeast-2.amazonaws.com/dev/";

export async function request(url, options) {
  try {
    const response = await fetch(`${baseUrl}${url}`, options);
    if (response.ok) {
      return response.json();
    }
    throw new Error("불러오기를 실패했습니다");
  } catch (error) {
    console.log(error);
  }
}
